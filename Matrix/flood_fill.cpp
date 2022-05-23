#include <iostream>
#include <vector>



void flood_fill(std::vector<std::vector<int>>& image, int x, int y, int src, int newColor)
{
	if(x < 0 || y < 0 || x > image.size()-1 || y > image[0].size()-1 || src == newColor)
	{
		return;
	}
	if(image[x][y] == src)
	{
		image[x][y] = newColor;
		// Print the changes - 
		for (int i = 0; i < image.size(); i++)
		       for (int j = 0; j < image[0].size(); j++)
		  
       
		          std::cout << image[i][j] << " \n"[j == image[0].size()-1];
		std::cout << "------------------------" << std::endl;
		// Recursive call - 
		flood_fill(image,x-1,y, src, newColor);
		flood_fill(image,x,y-1, src, newColor);
		flood_fill(image,x+1,y, src, newColor);
		flood_fill(image,x,y+1, src, newColor);
	}
	else
	{
		return;
	}

}


std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor)
{
	int source_color = image[sr][sc];
	flood_fill(image, sr, sc, source_color, newColor);
	return image;
}




int main()
{
	std::vector<std::vector<int>> v = {{0,0,0},
									   {0,1,1}};
								      // {1,0,1}};
	int sr = 1;
	int sc = 1;
	int newColor = 1;
	int m = v.size();
	int n = v[0].size();

	v = floodFill(v,sr,sc,newColor);
	for (int i = 0; i < m; i++)
       for (int j = 0; j < n; j++)
  
          // Prints ' ' if j != n-1 else prints '\n'          
          std::cout << v[i][j] << " \n"[j == n-1];




	return 0;
}