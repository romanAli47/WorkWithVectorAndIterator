#ifndef TEMPLATEFUNCTION_H
#define TEMPLATEFUNCTION_H

//������� ��� ����� �����
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
				throw InputValidationException("Error", WrongSymbolError, "��������� ���� �����. ��� ����� ����� ������������ ������ ����� 0-9 � �����(��� ����� � ������� ������).");
			if (number < leftBorder || number > rightBorder) {
				stringstream s;
				s << "�������� ����� ������ ���� � �������� �� " << leftBorder << " �� " << rightBorder << ".";
				throw InputValidationException("Error", RangeError, s.str());
			}
			return number;
		}
		catch (InputValidationException e)
		{
			cout << e.what() << endl;
			cin.clear();  //����� ���� ��������� ������
			while (cin.get() != '\n'); //fflush(stdin);
			cout << "��������� ����: ";
		}
		catch (...)
		{
			cout << "�������� ����������� ����������.";
			exit(1);
		}
	} while (true);

	return number;
}

#endif