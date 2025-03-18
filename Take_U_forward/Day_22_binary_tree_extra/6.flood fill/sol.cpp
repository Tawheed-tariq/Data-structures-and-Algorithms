class Solution {
    public:
        void setPixel(vector<vector<int>>& image, int x, int y, int color, int rows, int cols, int val){
            if((x < 0) || (x >= rows) || (y < 0) || (y >= cols) || (image[x][y] == color) || (image[x][y] != val)) return;
    
            image[x][y] = color;
            setPixel(image, x-1, y, color, rows, cols, val);
            setPixel(image, x+1, y, color, rows, cols, val);
            setPixel(image, x, y-1, color, rows, cols, val);
            setPixel(image, x, y+1, color, rows, cols, val);
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int rows = image.size(), cols = image[0].size();
            int val = image[sr][sc];
            setPixel(image, sr, sc, color, rows, cols, val);
            return image; 
        }
    };