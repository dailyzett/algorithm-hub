import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        
        Map<String, Integer> playerMap = new HashMap<>();
        for(int i=0; i<players.length; i++) {
            playerMap.put(players[i], i);
        }
    
        List<String> playerList = new ArrayList<>(Arrays.asList(players));
    
        for(String calling : callings) {
            int idx = playerMap.get(calling);
            
            String prevPlayer = playerList.get(idx-1);
            playerList.set(idx-1, calling);
            playerList.set(idx, prevPlayer);
            
            playerMap.put(calling, idx - 1);
            playerMap.put(prevPlayer, idx);
        }
        
        return playerList.toArray(new String[0]);
    }
}