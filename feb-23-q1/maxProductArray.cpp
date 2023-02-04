int maxProduct(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
        return -1;
    bool zero = false;
    long long productMax = arr[0], productMin = arr[0], resultProduct = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            productMax = 1, productMin = 1;
            zero = true;
            continue;
        }
        long long temp = max({productMax*arr[i],productMin*arr[i], (long long)arr[i]});
        productMin = min({productMax*arr[i],productMin*arr[i], (long long)arr[i]});
        productMax = temp;

        resultProduct = max(productMax,resultProduct);
        }
        if(zero == true) return max(resultProduct,(long long)0);
    return resultProduct;
    }