#include<iostream>
#include<vector>
using namespace std;
    
    void DFS(vector<vector<int> >&image,int sr,int sc,int newColor,int oldColor)
    {
        if(sc<0||sr<0|| sr>=image.size() || sc>=image[0].size() || image[sr][sc] != oldColor)
        return;
        image[sr][sc] = newColor;
        
        DFS(image,sr+1,sc,newColor,oldColor);
        DFS(image,sr-1,sc,newColor,oldColor);
        DFS(image,sr,sc+1,newColor,oldColor);
        DFS(image,sr,sc-1,newColor,oldColor);
    }

    vector<vector<int> > floodFill(vector<vector<int> >&image, int sr, int sc, int newColor) 
    {
    
        if(newColor == image[sr][sc])
        return image;
        DFS(image,sr,sc,newColor,image[sr][sc]);
        return image;
        
    }


int main()
{
    int n, m;
		cin >> n >> m;
		vector<vector<int> >image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		vector<vector<int> > ans = floodFill(image, sr, sc, newColor);
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[0].size();j++)
				cout << j << " ";
			cout << "\n";
		}

    return 0;
    
}