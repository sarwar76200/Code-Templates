using ll = long long int;
const int inf = 0x3f3f;
struct Node {
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSubarraySum;
    Node() {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
        totalSum = -inf;
    }
};

const int N = 1e5 + 5;
int arr[N + 1];
Node Tree[4 * N + 10];
int n;

Node merge(Node leftChild, Node rightChild) {
    Node parentNode;
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum, leftChild.totalSum + rightChild.maxPrefixSum);
    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum, rightChild.totalSum + leftChild.maxSuffixSum);
    parentNode.totalSum = leftChild.totalSum + rightChild.totalSum;
    parentNode.maxSubarraySum = max({leftChild.maxSubarraySum, rightChild.maxSubarraySum, leftChild.maxSuffixSum + rightChild.maxPrefixSum});
    return parentNode;
}

void build(int ind = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        Tree[ind].totalSum = arr[l];
        Tree[ind].maxSuffixSum = arr[l];
        Tree[ind].maxPrefixSum = arr[l];
        Tree[ind].maxSubarraySum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind, l, mid);
    build(2 * ind + 1, mid + 1, r);
    Tree[ind] = merge(Tree[2 * ind], Tree[2 * ind + 1]);
}

Node get_query(int& a, int& b, int ind = 1, int l = 0, int r = n - 1) {
    if (l > b || r < a) {
        Node nullNode;
        return nullNode;
    }
    if (l >= a && r <= b) {
        return Tree[ind];
    }
    int mid = (l + r) / 2;
    Node left = get_query(a, b, 2 * ind, l, mid);
    Node right = get_query(a, b, 2 * ind + 1, mid + 1, r);
    Node res = merge(left, right);
    return res;
}

void update(int& pos, int& val, int ind = 1, int l = 0, int r = n - 1) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        arr[l] = val;
        Tree[ind].totalSum = arr[l];
        Tree[ind].maxSuffixSum = arr[l];
        Tree[ind].maxPrefixSum = arr[l];
        Tree[ind].maxSubarraySum = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(pos, val, 2 * ind, l, mid);
    } else {
        update(pos, val, (2 * ind) + 1, mid + 1, r);
    }
    Tree[ind] = merge(Tree[2 * ind], Tree[2 * ind + 1]);
}