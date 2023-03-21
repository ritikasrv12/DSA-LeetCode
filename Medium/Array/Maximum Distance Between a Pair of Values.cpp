int i = 0, j = 0, maxDist = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                i++;
            } else {
                maxDist = max(maxDist, j - i);
                j++;
            }
        }
        return maxDist;
