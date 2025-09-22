class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int res = 0;
        int max_i=0;
        // start to finish
        while(i<height.size()){
            if(height[i]>0){
                int current_i=i;
                int current_height=height[i];
                int total_block=0;
                int max_height=0;
                max_i=i;
                int total_block_on_max=0;
                i++;
                while(i<height.size() && current_height>height[i]){
                    if(height[i]>=max_height){
                        max_i=i;
                        max_height=height[i];
                        total_block_on_max = total_block;
                    }
                    total_block+=height[i];
                    i++;
                }
                // found before end
                if(i<height.size()){
                    res+=(i-current_i-1)*current_height-total_block;
                    i--;
                }

                // found an end
                else {
                    res+=(max_i-current_i-1)*max_height-total_block_on_max;
                }
            }
            i++;
        }

        max_i--;
        cout << max_i << endl;

        // finish to max
        i = height.size()-1;
        int min_i = max_i;
        while(i>min_i){
            if(height[i]>0){
                int current_i=i;
                int current_height=height[i];
                int total_block=0;
                int max_height=0;
                max_i=i;
                int total_block_on_max=0;
                i--;
                while(i>min_i && current_height>height[i]){
                    if(height[i]>=max_height){
                        max_i=i;
                        max_height=height[i];
                        total_block_on_max = total_block;
                    }
                    total_block+=height[i];
                    i--;
                }
                // cout << current_i << " - " << max_i << "*" << max_height << " - " << total_block_on_max << endl;
                // found before end
                if(i>min_i){
                    // cout << "a";
                    res+=(current_i-i-1)*current_height-total_block;
                    i++;
                }

                // found an end (max)
                else {
                    // cout << "b";
                    res+=(current_i-min_i-1)*max_height-total_block_on_max;

                }
            }
            i--;

        }

        return res;
    }
};