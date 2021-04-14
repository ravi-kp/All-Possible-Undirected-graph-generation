#include<iostream>
#include<bits/stdc++.h>
#include<boost/config.hpp>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/erdos_renyi_generator.hpp>
#include<boost/random/linear_congruential.hpp>
#include<boost/graph/isomorphism.hpp>
#include<boost/graph/graph_utility.hpp>
using namespace std;
typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS,boost::no_property,boost::property<boost::edge_name_t,std::string>> Graph;
int main()
{
  int num_vertices,num_edge,max_edge,flag;
  cout<<"enter number of vertices:";
  cin>>num_vertices; 
  vector<Graph> v;
  /*cout<<"enter number of edges:";
  cin>>num_edge;*/
  max_edge=num_vertices*(num_vertices-1)/2;
  ofstream graph_list("graphviz.dot");
  for(int i=0;i<((int)(pow(2,max_edge)));i++)
  {
  	Graph g(num_vertices);
  	flag=0;
  	for(int j=0;j<max_edge;j++)
  	{
  		if((i & (int)(pow(2,j))) == (int)(pow(2,j)))
  		{
  			if(j<num_vertices)
  			{
  				add_edge(j,(j+1)%num_vertices,g);
  			}
  			if(j>=num_vertices)
  			{
  				add_edge(j%num_vertices,(j+2)%num_vertices,g);
  			}
  		}
  	}
  
  	graph_list<<"graph G {"<<endl;
  	for(int i=0;i<num_vertices;i++)
    {
      graph_list<<i<<" "<<"[label="<<i<<"]"<<endl;
    }
    auto epair=edges(g);
    for(auto itr=epair.first;itr!=epair.second;itr++)
    { 
     graph_list<<source(*itr,g)<<" -- "<<target(*itr,g)<<std::endl;
    }
    graph_list<<"}"<<endl;
  }
 
  return 0;
}
