    vector<int> flip;
    int i;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        i = 0;
        return isMatchingVoyage(root, voyage) ? flip : vector<int>{-1};
    }
    bool isMatchingVoyage(TreeNode* root, vector<int>& v){
        if(!root) return true;
        if(root -> val != v[i++]) return false;
        if(root -> left && root -> left -> val != v[i]){
            flip.push_back(root -> val);
            return isMatchingVoyage(root -> right, v) && isMatchingVoyage(root -> left, v);
        }
        return isMatchingVoyage(root -> left, v) && isMatchingVoyage(root -> right, v);
    }