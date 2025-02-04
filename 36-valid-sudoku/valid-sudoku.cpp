class Solution {
public:             //col!=row
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,pair<set<int>,pair<set<int>,set<int>>>> exist;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char current=board[i][j];
                if(current=='.')continue;

                int subbox=(i / 3) * 10 + (j / 3);
                auto it=exist.find(current);
                if(it==exist.end()){
                    pair<set<int>,pair<set<int>,set<int>>> pair1 = {{subbox}, {{i}, {j}}};
                    exist.insert({current,pair1});
                }else{
                    if (it->second.first.count(subbox)){
                        // cout << 1 << endl;
                        // cout << current << " " << subbox << " " << i << " " << j ;
                        return false;
                    }
                    it->second.first.insert(subbox);
                    if (it->second.second.first.count(i) || it->second.second.second.count(j)){
                        // cout << 2 << endl;
                        // cout << current << " " << subbox << " " << i << " " << j ;
                        return false;
                    }
                    it->second.second.first.insert(i);
                    it->second.second.second.insert(j);
                    // cout << i << " " << j << endl;
                }
            }
        }
        return true;
    }
};
        // <cell:"5"<subboxes:[1,2,3,10,11,12,20,21,22],col/row[1,2,3,4,5,6,7,8,9]>>
        // subboxes : (i/3)*10+(j/3)