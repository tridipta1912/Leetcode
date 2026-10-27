class Solution
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths)
    {
        struct Trie
        {
            string name;
            unordered_map<string, Trie*> child;
            bool del = false;
        };

        Trie* root = new Trie();

        for (auto& path : paths)
        {
            Trie* node = root;
            for (auto& dir : path)
            {
                if (!node->child.count(dir))
                {
                    node->child[dir] = new Trie();
                    node->child[dir]->name = dir;
                }
                node = node->child[dir];
            }
        }

        unordered_map<string, vector<Trie*>> map;

        function<string(Trie*)> ser = [&](Trie* node) -> string
        {
            if (node->child.empty())
                return string();
            vector<pair<string, string>> subs;
            for (auto& [k, child] : node->child)
                subs.emplace_back(k, ser(child));
            sort(subs.begin(), subs.end());
            string res;
            for (auto& [k, s] : subs)
                res += k + "(" + s + ")";
            map[res].push_back(node);
            return res;
        };

        ser(root);

        for (auto& [s, nodes] : map)
            if (nodes.size() > 1)
                for (auto* node : nodes)
                    node->del = true;

        vector<vector<string>> res;
        vector<string> path;

        function<void(Trie*)> collect = [&](Trie* node)
        {
            for (auto& [k, child] : node->child)
            {
                if (child->del)
                    continue;
                path.push_back(k);
                res.push_back(path);
                collect(child);
                path.pop_back();
            }
        };

        collect(root);
        return res;
    }
};
