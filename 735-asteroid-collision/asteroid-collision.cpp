class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,int>> s;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty()){
                s.push({asteroids[i],i});
                continue;
            }
            if(asteroids[i]>0){
                s.push({asteroids[i],i});
            }else if(s.top().first>0){
                while(!s.empty() && s.top().first>0 && asteroids[i]*-1>s.top().first){
                    s.pop();
                }
                if(!s.empty() && s.top().first>0 && asteroids[i]*-1==s.top().first){
                    s.pop();
                }else if(s.empty() || asteroids[i]*-1>s.top().first){
                    s.push({asteroids[i],i});
                }
                // if(asteroids[i]*-1>s.top().first){
                //     s.pop();
                //     if(s.empty()){
                //         s.push({asteroids[i],i});
                //     }
                //     else if(s.top().second+2==i){
                //         if(s.top().first<0){
                //             s.push({asteroids[i],i});
                //         } 
                //         else if(asteroids[i]*-1>s.top().first){
                //             s.pop();
                //             s.push({asteroids[i],i});
                //         }else if(asteroids[i]*-1==s.top().first){
                //             s.pop();
                //         }
                //     }
                // }else if(asteroids[i]*-1==s.top().first){
                //     s.pop();
                // }
            }else{
                s.push({asteroids[i],i});
            }
        }
        vector<int> res;
        while(!s.empty()){
            res.insert(res.begin(),s.top().first);
            s.pop();
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         stack<pair<int,int>> s;
//         for(int i=0;i<asteroids.size();i++){
//             if(s.empty()){
//                 s.push({asteroids[i],i});
//                 continue;
//             }
//             if(asteroids[i]>0){
//                 s.push({asteroids[i],i});
//             }else if(s.top().first>0){
//                 if(asteroids[i]*-1>s.top().first){
//                     s.pop();
//                     if(s.empty()){
//                         s.push({asteroids[i],i});
//                     }
//                     else if(s.top().second+2==i){
//                         if(s.top().first<0){
//                             s.push({asteroids[i],i});
//                         } 
//                         else if(asteroids[i]*-1>s.top().first){
//                             s.pop();
//                             s.push({asteroids[i],i});
//                         }else if(asteroids[i]*-1==s.top().first){
//                             s.pop();
//                         }
//                     }
//                 }else if(asteroids[i]*-1==s.top().first){
//                     s.pop();
//                 }
//             }else{
//                 s.push({asteroids[i],i});
//             }
//         }
//         vector<int> res;
//         while(!s.empty()){
//             res.insert(res.begin(),s.top().first);
//             s.pop();
//         }
//         return res;
//     }
// };