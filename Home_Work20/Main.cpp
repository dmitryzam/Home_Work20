﻿#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
// Функция по заполнению массива случайными числами:
template<typename T>
void fill_arr(T arr[], const int length) {
	srand(time(NULL));	// генератор случайных числе.
	for (int i = 0; i < length; i++)	// перебираем в цикле каждый элемент массива,
		arr[i] = rand() % 10;			// и инициализируем каждый элемент случайным числом в диапазоне 0...9.
}
// Функция по выводу в консоль массива:
template<typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)	// перебираем в цикле каждый элемент массива,
		std::cout << arr[i] << ", ";	// и выводим каждый элемент в консоль.
	std::cout << "\b\b }" << std::endl;
}
// Функция возвращает первый индекс необходимого элемента.
// Также функция принимает переменную begin для поиска с определенного места:
template<typename T>
T search_index(T arr[], const int length, T num, int begin = 0) {
	if (begin < 0 || begin >= length)		// если значение begin будет меньше 0 или больше/равно размеру массива,
		return -2;							// то возвращаем -2 в блок main и завершаем выполнение данной функции.
	for (int i = begin; i < length; i++)	// перебираем в цикле каждый элемент массива,
		if (arr[i] == num)					// и ищем значение необходимого числа, кот. передали функции,
			return i;						// если будет найдено значение необходимого элемента, то возвращаем индекс этого элемента в блок main.
	return -1;							// если не будет найдено значение необходимого элемента, то возвращаем -1 в блок main.
}
// Функция возвращает последний индекс необходимого элемента.
// Также функция принимает переменную begin для поиска с определенного места:
template<typename T>
T search_last_index(T arr[], const int length, T num, int begin = length - 1) {
	if (begin < 0 || begin >= length)		// если значение begin будет меньше 0 или больше/равно размеру массива,
		return -2;							// то возвращаем -2 в блок main и завершаем выполнение данной функции.
	for (int i = begin; i >= 0; i--)		// перебираем в цикле каждый элемент массива, начиная с конца,
		if (arr[i] == num)					// и ищем значение необходимого числа, кот. передали функции,
			return i;						// если будет найдено значение необходимого элемента, то возвращаем индекс этого элемента в блок main.
	return -1;					// если не будет найдено значение необходимого элемента, то возвращаем -1 в блок main.
}
// Функция по нахождению минимального числа в массиве и возврата его значения в блок main:
template<typename T>
T arr_min(T arr[], const int length) {
	int min = arr[0];						// присваиваем переменной min зачение нулевого индекса в массиве.
	for (int i = 1; i < length; i++)		// перебираем в цикле каждый элемент массива,
		min = min > arr[i] ? arr[i] : min;	// и сравниваем их с переменной min с помощью тернарного оператора, и на каждой итерации перезаписываем переменную min.
	return min;								// по завершению цикла возвращаем в блок main значение переменной min.
}
// Функция по нахождению максимального числа в массиве и возврата его значения в блок main:
template<typename T>
T arr_max(T arr[], const int length) {
	double max = arr[0];					// присваиваем переменной max зачение нулевого индекса в массиве.
	for (int i = 1; i < length; i++)		// перебираем в цикле каждый элемент массива,
		max = max < arr[i] ? arr[i] : max;	// и сравниваем их с переменной max с помощью тернарного оператора, и на каждой итерации перезаписываем переменную max.
	return max;								// по завершению цикла возвращаем в блок main значение переменной max.
}
// Функция по нахождению среднего арифметического значения всех элементов в массиве и возврата его значения в блок main:
template<typename T>
double mean_value(T arr[], const int length) {
	double mean = 0;						// создаем переменную и присваеваем ей 0.
	for (int i = 0; i < length; i++)		// перебираем в цикле каждый элемент массива,
		mean += arr[i];						// и добавляем значение каждого элемента в переменную mean,
	return mean / length;					// и возвращаем в блок main значение переменной mean.
}
// Функция по выводу чисел из массива в заданном диапазоне:
template<typename T>
void range(T arr[], const int length, T left, T right) {
	if (left == right)						// Если заданные числа равны, то выводим "Ошибку ввода".
		std::cout << "Ошибка ввода заданного диапазона!";
	if (left > right)						// Если первое заданное число больше воторого, 
		std::swap(left, right);				// то поменяем местами их значения с помощью функции swap().
	std::cout << "Числа из массива, входящие в заданный диапазон:\n";
	for (int i = 0; i < length; i++)				// перебираем в цикле каждый элемент массива,
		if (arr[i] >= left && arr[i] <= right)		// если элементы в массиве входят в заданный диапазон,
			std::cout << arr[i] << ", ";			// то выводим их в консоль.
	std::cout << "\b\b." << std::endl;
	std::cout << std::endl;
}
// Функция возвращает кол-во вхождений переданного элемента в массив:
template<typename T>
T count(T arr[], const int length, T element) {
	int counter = 0;						// создаем переменную счетчика и присваеваем ей 0.
	for (int i = 0; i < length; i++)		// перебираем в цикле каждый элемент массива,
		if (arr[i] == element)				// если элемент совпадает с заданным числом (element),
			counter++;						// то счетчик инкрементируем.
	return counter;							// выводим из функции значение счетчика в блок main.
}
// Функция по сортировке элементов в массиве пузырьковым методом:
template<typename T>
void sort_arr(T arr[], const int length) {
	for (int i = length - 1; i > 0; i--)		// данным циклом ограничиваем последние числа в массиве.
		for (int j = 0; j < i; j++)				// перебираем в цикле каждый элемент массива,
			if (arr[j] > arr[j + 1])				// если элемент позиции i больше элемента i+1,
				std::swap(arr[j], arr[j + 1]);	// то меняем их местами.
}

int main() {
	setlocale(LC_ALL, "RU");
	int n, m;

	const int size = 20;
	int arr[size]{};

	// Инициализируем массив с помощью функции fiil_arr[]:
	fill_arr(arr, size);

	// Выведем массив в консоль:
	std::cout << "Массив:\n";
	print_arr(arr, size);
	std::cout << std::endl;
	
	// Попробуем найти индекс необходимого числа через функцию search_index():
	std::cout << "Введите необходимое число для определения его индекса в массиве -> ";
	std::cin >> n;
	if (search_index(arr, size, n) == -1)
		std::cout << "Необходимое число отсутствуем в массиве!";
	else
		std::cout << "Индекс необходимого числа будет равен " << search_index(arr, size, n) << std::endl;
	std::cout << std::endl;

	// Также попробуем найти индекс необходимого числа через функцию search_index(),
	// только при этом введем число, означающее поиск с определенной позиции в массиве:
	std::cout << "Введите необходимое число для определения его индекса в массиве -> ";
	std::cin >> n;
	std::cout << "Введите число (индекс) с которого начнется поиск в массиве -> ";
	std::cin >> m;
	if (search_index(arr, size, n, m) == -1)
		std::cout << "Необходимое число отсутствуем в массиве!\n";
	else if (search_index(arr, size, n, m) == -2)
		std::cout << "Такой индекс отсутствуем в массиве!\n";
	else
		std::cout << "Индекс необходимого числа будет равен " << search_index(arr, size, n, m) << std::endl;
	std::cout << std::endl;
	
	// Попробуем найти последний индекс необходимого числа через функцию search_last_index(),
	// также введем число, означающее поиск с определенной позиции в массиве:
	std::cout << "Введите необходимое число для определения его индекса в массиве -> ";
	std::cin >> n;
	std::cout << "Введите число (индекс) с которого начнется поиск в массиве -> ";
	std::cin >> m;
	if (search_last_index(arr, size, n, m) == -1)
		std::cout << "Необходимое число отсутствуем в массиве!\n";
	else if (search_last_index(arr, size, n, m) == -2)
		std::cout << "Такой индекс отсутствуем в массиве!\n";
	else
		std::cout << "Индекс необходимого числа будет равен " << search_last_index(arr, size, n, m) << std::endl;
	std::cout << std::endl;
	
	// Попробуем найти минимальное число в массиве с помощью функции arr_min():
	std::cout << "Минимальное число в массиве равно " << arr_min(arr, size) << std::endl;
	std::cout << std::endl;

	// Попробуем найти максимальное число в массиве с помощью функции arr_max():
	std::cout << "Максимальное число в массиве равно " << arr_max(arr, size) << std::endl;
	std::cout << std::endl;

	// Попробуем найти среднее арифметическое значение в массиве с помощью функции mean_value():
	std::cout << "Среднее арифметическое значение всех элементов массива равно " << mean_value(arr, size) << std::endl;
	std::cout << std::endl;

	// Найдем все элементы в массиве с помощью функции range(), в которую передадим диапазон:
	std::cout << "Введите два числа для указания диапазона по выводу чисел из массива -> ";
	std::cin >> n >> m;
	range(arr, size, n, m);

	// Функция по подсчету необходимого элемента в массиве и вывода в блок main данного кол-ва:
	std::cout << "Введите число для его подсчета в массиве -> ";
	std::cin >> n;
	if (count(arr, size, n) == 0)
		std::cout << "Число " << n << " отсутствует в массиве.\n\n";
	else
		std::cout << "Количество заданного числа " << n << " в массиве равно " << count(arr, size, n) << ".\n";
	std::cout << std::endl;

	// Попробуем отсортировать элементы в массиве с помощью функции sort_arr() пузырьковым методом:
	std::cout << "Отсортированный массив:\n";
	sort_arr(arr, size);
	//std::sort(arr, arr + size); // Также можно воспользоваться функцией для быстрой сортировке.
	print_arr(arr, size);
	
	return 0;
}