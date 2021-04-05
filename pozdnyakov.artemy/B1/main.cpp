int main(int argc, char* argv[])
{
    if (argv[1] == "1")
    {
      task1(argv + 2);
    }
    else if (argv[1] == "2")
    {
      // do task 2
    }
    else if (argv[1] == "3")
    {
      // do task 3
    }
    else if (argv[1] == "4")
    {
      // do task 4
    }
    else
    {
      throw -1; // arg exception gmix
    }
}
