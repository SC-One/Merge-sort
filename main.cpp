#include <iostream>
template <typename Type>
[[deprecated("*[from,to)* ,Dont forget to free heap xD")]]

Type* copyArray(Type input[],int from, int to) {
  int sizeOut{to - from};
  Type* output{new Type[sizeOut]};
  for (int i{0}; i < sizeOut; ++i) {
    output[i] = input[from + i];
  }
  return output;
}

template <typename Type>
void merge(Type first[], int h, Type second[], int m, Type input[]) {
  for (int firstInd{0}, secondInd{0}, counter{0}; firstInd < h || secondInd < m;
       counter++) {
    input[counter] = (first[firstInd] < second[secondInd] ? first[firstInd]
                                                          : second[secondInd]);
    input[counter] == first[firstInd] ? firstInd++ : secondInd++;
  }
}

template <typename Type>
void mergeSort(Type arr[], int sizeArr) {
  auto h{sizeArr / 2};
  auto m{sizeArr - h};
  if (sizeArr > 1) {
    auto left{copyArray(arr, 0, h)};
    auto right{copyArray(arr, h, sizeArr)};
    mergeSort(left, h);
    mergeSort(right, m);
    merge(left, h, right, m, arr);
  }
}

int main() {
  int a[10] = {2, 8, 4, 12, 4, 53, 2, 1, 31, 2};
  mergeSort<int>(a, 10);

  for (auto i{0}; i < 10; i++) std::cout << a[i] << "\t";
  return 0;
}
