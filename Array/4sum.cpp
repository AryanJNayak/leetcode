vector<vector<int>> fourSum(vector<int> &nums, int target)
{

  int n = nums.size();
  if (n < 4)
    return {};

  vector<vector<int>> fourSum;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 3; i++)
  {
    for (int j = i + 1; j < n - 2; j++)
    {
      long long sum2 = (long long)target - (nums[i] + nums[j]);
      int start = j + 1, end = n - 1;

      while (start < end)
      {
        if (sum2 == (nums[start] + nums[end]))
        {
          vector<int> temp(4, 0);
          temp[0] = nums[i];
          temp[1] = nums[j];
          temp[2] = nums[start];
          temp[3] = nums[end];
          fourSum.push_back(temp);
          while (start < end && nums[start] == temp[2])
            ++start;
          while (start < end && nums[end] == temp[3])
            --end;
        }
        else if (sum2 < nums[start] + nums[end])
        {
          end--;
        }
        else
        {
          start++;
        }
      }
      while (j + 1 < n && nums[j] == nums[j + 1])
        j++;
    }
    while (i + 1 < n && nums[i] == nums[i + 1])
      i++;
  }
  return fourSum;
}