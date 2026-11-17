/*********************************
 * Автор:   Хан Кирилл            *
 * Задание: Функции               *
 * Вариант: 26                    *
 *********************************/

#include <iostream>

using namespace std;

double sumValues(const double values[], int count) {
  double sum = 0.0;
  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    sum += values[elementIndex];
  }
  return sum;
}

void divideValues(const double numerators[], const double denominators[], double result[], int count) {
  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    result[elementIndex] = numerators[elementIndex] / denominators[elementIndex];
  }
}

int main() {
  const int maxCount = 100;
  const double maxValue = 1000.0;
  double numeratorValues[maxCount], denominatorValues[maxCount], quotientValues[maxCount];
  double numeratorSum, denominatorSum, quotientSum;
  int count;

  if (!(cin >> count) || count < 1 || count > maxCount) {
    cout << "INVALID";
    return 1;
  }
  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    if (!(cin >> numeratorValues[elementIndex]) || numeratorValues[elementIndex] < -maxValue || numeratorValues[elementIndex] > maxValue) {
      cout << "INVALID";
      return 1;
    }
  }
  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    if (!(cin >> denominatorValues[elementIndex]) || denominatorValues[elementIndex] < -maxValue || denominatorValues[elementIndex] > maxValue || denominatorValues[elementIndex] == 0.0) {
      cout << "INVALID";
      return 1;
    }
  }

  divideValues(numeratorValues, denominatorValues, quotientValues, count);
  numeratorSum = sumValues(numeratorValues, count);
  denominatorSum = sumValues(denominatorValues, count);
  quotientSum = sumValues(quotientValues, count);

  cout << "F:";
  for (int elementIndex = 0; elementIndex < count; ++elementIndex) {
    cout << " " << quotientValues[elementIndex];
  }
  cout << "\nSum G: " << numeratorSum << "\nSum H: " << denominatorSum << "\nSum F: " << quotientSum;
  return 0;
}
