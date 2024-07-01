#include <iostream>
#include <vector>

// 快速排序的辅助函数，用于分区
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为枢轴
    int left = low + 1;
    int right = high;

    while (true) {
        // 从左向右找第一个大于或等于枢轴的元素
        while (left <= right && arr[left] < pivot) {
            left++;
        }
        // 从右向左找第一个小于或等于枢轴的元素
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        // 如果左右指针没有相遇，交换元素
        if (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        } else {
            break;
        }
    }
    // 将枢轴放到正确位置
    std::swap(arr[low], arr[right]);
    return right; // 返回枢轴的索引
}

// 快速排序的递归函数
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 分区索引
        quickSort(arr, low, pi - 1); // 对左子数组进行递归排序
        quickSort(arr, pi + 1, high); // 对右子数组进行递归排序
    }
}

// 打印数组
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
