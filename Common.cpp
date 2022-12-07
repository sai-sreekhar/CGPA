int getGradePoint(char grade)
{
    switch (grade)
    {
    case 'S':
        return 10;
    case 'A':
        return 9;
    case 'B':
        return 8;
    case 'C':
        return 7;
    case 'D':
        return 6;
    case 'E':
        return 5;
    case 'F':
        return 0;
    }
    return 0;
}