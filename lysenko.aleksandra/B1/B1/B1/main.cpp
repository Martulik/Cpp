#include <stdexcept>

bool correctNumberOfArgs(int argc);///��������� ��� argc � ��������� �� 2 �� 4, ���� ��� ����������� ����������
bool correctData(char* argv);///��������� �� �������� �� ������ � ���� ��������
bool isTypeOfSort(char* argv);///��������� �� ascending/descending � ���������� 1 � ������ ����������, � ��������� ������ ���������� 0

int main(int argc, char* argv[])
{
  if (correctNumberOfArgs(argc))
  {
    if (argc == 2)
    {
      ///����� 3 �������
    }
    else if (argc == 3)
    {
      if (correctData(argv[1])) 
      {
        if (isTypeOfSort(argv[2]))
        {
          ///����� 1 �������
        }
        else
        {
          //����� 2 �������
        }
      }
      throw std::invalid_argument("Format of task's number is not correct");
    }
    else
    {
      ///����� 4 �������
    }
  }
  else
  {
    throw std::invalid_argument("Invalid number of arguments");
  }
  return 0;
}
