class Solution {
public:
  int maxArea(vector<int> &height) {
    int width = height.size();
    int left = 0;
    int right = width - 1;
    int next;
    int max = 0;

    while (left < right) {
      int area = std::min(height[left], height[right]) * (right - left);

      if (area > max) {
        max = area;
      }

      if (height[left] > height[right]) {
        next = right - 1;

        while ((next > left) && (height[next] <= height[right])) {
          --next;
        }

        right = next;
      }
      else {
        next = left + 1;

        while ((next < right) && (height[next] <= height[left])) {
          ++next;
        }

        left = next;
      }
    }

    return max;
  }
};