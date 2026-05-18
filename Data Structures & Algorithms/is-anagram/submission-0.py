class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        size_s, size_t = len(s), len(t)
        if size_s != size_t:
            return False
        net_cnt = dict({})
        for char_s, char_t in zip(s, t):
            net_cnt[char_s] = net_cnt.get(char_s, 0) + 1
            net_cnt[char_t] = net_cnt.get(char_t, 0) - 1
        
        for value in net_cnt.values():
            if value:
                return False
        return True

        