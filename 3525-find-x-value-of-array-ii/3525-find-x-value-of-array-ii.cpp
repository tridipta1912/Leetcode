class Solution
{
    struct Node
    {
        int prod;
        array<int, 5> cnt;

        Node()
        {
            prod = 1;
            cnt.fill(0);
        }

        Node(int k)
        {
            prod = 1 % k;
            cnt.fill(0);
        }
    };

    int n;
    int k;
    vector<int> nums;
    vector<Node> seg;

    Node mergeNodes(const Node& a, const Node& b)
    {
        Node c(k);

        c.prod = a.prod * b.prod % k;

        for (int r = 0; r < k; r++)
        {
            c.cnt[r] += a.cnt[r];

            int nr = a.prod * r % k;
            c.cnt[nr] += b.cnt[r];
        }

        return c;
    }

    Node makeNode(int val)
    {
        Node res(k);

        int p = val % k;

        res.prod = p;
        res.cnt[p] = 1;

        return res;
    }

    void build(int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = mergeNodes(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            seg[node] = makeNode(val);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        seg[node] = mergeNodes(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql)
    {
        if (ql <= l)
            return seg[node];

        int mid = (l + r) / 2;

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql);

        Node left = query(node * 2, l, mid, ql);
        Node right = query(node * 2 + 1, mid + 1, r, ql);

        return mergeNodes(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries)
    {
        this->nums = nums;
        this->k = k;
        n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries)
        {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};