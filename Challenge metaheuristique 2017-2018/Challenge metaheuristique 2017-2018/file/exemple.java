//==========================================================
import  java.util.Random; 
//==========================================================
class Solution {
	int data[]; 
	int cost; 
	int size; 
	Solution(int _size)
		{
		size=_size; 
		data= new int [size];
		for(int j=0;j<size;j++) 
			data[j]=j; 
		}
	Solution(Solution s)
		{
		size=s.size; 
		data= new int [size];
		for(int j=0;j<size;j++) 
			data[j]=s.data[j]; 
		}
	int setCost(permutation i)
		{
		cost=i.evaluate_solution(data); 
		return cost; 
		}
	void print() 
		{
		System.out.println("Cost : "+cost); 
		System.out.print("Solution : ["+data[0]); 
		for(int j=1;j<size;j++) System.out.print(","+data[j]);
		System.out.println("]"); 
		}
}
//==========================================================
class Mouvement {
static Solution inverse(Solution s, int j1, int j2)
		{
		Solution r=new Solution(s); 
		int tmp=r.data[j1]; 
		r.data[j1]=r.data[j2]; 
		r.data[j2]=tmp; 
		return r; 
		}
} 
//==========================================================
class Voisins {
	int size; 
	Solution data[]; 
	int best; 
	Voisins(Solution s)
		{
		size=s.size-1; 
		data=new  Solution[size]; 
		for(int j=0;j<size;j++) 
			data[j]=Mouvement.inverse(s,j,j+1); 
		}
	Solution getBest(permutation i)
		{
		for(int j=0;j<size;j++) data[j].setCost(i); 
		best=0; 
		for(int j=1;j<size;j++) 
			if(data[best].cost>data[j].cost)
				best=j; 
		return data[best]; 
		}
	void print()
		{
		for(int j=0;j<size;j++) 
			{
			System.out.println(j+")"); 
			data[j].print(); 
			}
		}
}
//==========================================================
class Initialization {
	static Solution random(int size)
		{
		Solution s=new Solution(size); 
		Random r = new Random();
		for(int j=0;j<size;j++) 
			s=Mouvement.inverse(s,r.nextInt(size),r.nextInt(size)); 
		return s; 
		}
}
//==========================================================
public class Metaheuristics {
	//credits 
	static void credits()
		{
		permutation i=new permutation(); 
		int size=i.set_instance(56); 
		System.out.println(size);
		int s[]= new int [size];
		for(int j=0;j<size;j++) s[j]=j; 
		System.out.println(i.get_machines());
		i.set_credits(501); 
		for (int j=0; j<1; j++)
			System.out.println(i.evaluate_solution(s));
		}
	//simple solution
	static Solution simple_solution()
		{
		permutation i=new permutation(); 
		int size=i.set_instance(56); 
		Solution s=new Solution(size); 
		s.setCost(i); 
		s.print(); 
		return s; 
		}
	//random
	static Solution random_solution(int number)
		{
		permutation i=new permutation(); 
		int size=i.set_instance(number); 
		Solution s=Initialization.random(size); 
		s.setCost(i); 
		s.print(); 
		return s; 
		}
	//Recherche Locale
	static Solution rechercheLocale(int number)
		{
		permutation i=new permutation(); 
		int size=i.set_instance(number); 
		Solution s=Initialization.random(size); 
		s.setCost(i);
		s.print();
		boolean improvement=true;  
		while (improvement)
			{
			Voisins v=new Voisins(s); 
			Solution tmp=v.getBest(i);
			improvement=(tmp.cost<s.cost);  
			if(improvement) {s=tmp; s.print(); }; 
			}
		return s; 
		}

	static public void main(String[] args) {
		//credits(); 
		//simple_solution(); 
		//random_solution(56);
		rechercheLocale(56); 
	}
}

