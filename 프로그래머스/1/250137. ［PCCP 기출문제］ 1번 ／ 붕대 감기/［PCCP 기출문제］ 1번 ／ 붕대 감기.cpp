#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int cast_time = bandage[0];
    int recovery_per_seconds = bandage[1];
    int additional_recovery = bandage[2];
    
    int max_time = attacks[attacks.size()-1][0];
    map<int, int> mp;
    for(vector<int> attack: attacks) {
        int attack_time = attack[0];
        int damage = attack[1];
        mp[attack_time] = damage;
    }
    
    int max_health = health;
    bool is_attacked = false;
    int count = 0;
    for(int i=0; i<=max_time; i++) {

        if(mp.find(i) != mp.end()) {         //공격이 있는경우
            if(count >= cast_time) {
                health = min(max_health, health + additional_recovery);
                count = 0;
            }
            health -= mp[i];
            count = 0;
        } else {             //공격이 없는경우   
            if(health < max_health) {
                health = min(max_health, health + recovery_per_seconds);
            }
            
           count++;
            if (count >= cast_time) { // 추가 회복 조건을 만족하는 경우
                health = min(max_health, health + additional_recovery);
                count = 0; // 추가 회복 이후 카운터 초기화
            }
        }    
        if (health <= 0) {
            return -1;
        }
    }
        
    return health;
}