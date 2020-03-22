bool isCyclicUtil(int v, bool visited[], bool recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        for(i = pairs[v].winner; i != pairs[v].loser; i++) 
        { 
            if ( !visited[i] && isCyclicUtil(i, visited, recStack) ) 
                return true; 
            else if (recStack[i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 

bool isCyclic()
{

    bool visited[candidate_count]; 
    bool recStack[candidate_count]; 
    
    for(int i = 0; i < candidate_count; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    }
    
    for(int i = 0; i < candidate_count; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
}
