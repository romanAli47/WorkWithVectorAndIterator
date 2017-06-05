#ifndef TEMPLATEFUNCTION_H
#define TEMPLATEFUNCTION_H

//Функция для ввода числа
template <class T>
T numberInputWithBrackets(const T leftBorder, const T rightBorder)
{
	cout << "(" << leftBorder << "-" << rightBorder << "): ";
	T number = numberInput<T>(leftBorder, rightBorder);

	return number;
}

template <class T>
T numberInput(const T leftBorder, const T rightBorder)
{
	T number;

	do {
		try
		{
			cin >> number;
			if (!cin || cin.peek() != '\n')
				throw InputValidationException("Error", WrongSymbolError, "Невернный ввод числа. При вводе можно использовать только цифры 0-9 и точку(для чисел с дробной частью).");
			if (number < leftBorder || number > rightBorder) {
				stringstream s;
				s << "Вводимое число должно быть в пределах от " << leftBorder << " до " << rightBorder << ".";
				throw InputValidationException("Error", RangeError, s.str());
			}
			return number;
		}
		catch (InputValidationException e)
		{
			cout << e.what() << endl;
			cin.clear();  //Сброс всех состояний потока
			while (cin.get() != '\n'); //fflush(stdin);
			cout << "Повторите ввод: ";
		}
		catch (...)
		{
			cout << "Возникло неизвестное исключение.";
			exit(1);
		}
	} while (true);

	return number;
}

#endif