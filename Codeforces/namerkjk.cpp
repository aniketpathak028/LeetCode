for (int i = 0; i < n; i++)
{
    if (sum[i] < 0)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sum[j] > 0)
            {
                while (sum[j] != 0 || sum[i] != 0)
                {
                    sum[i]++;
                    sum[j]--;
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
            else
                continue;
        }
    }
    else if (sum[i] == 0)
    {
        continue;
    }
    else
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sum[j] < 0)
            {
                while (sum[i] != 0 || sum[j] != 0)
                {
                    sum[i]--;
                    sum[j]++;
                    cout << j + 1 << " " << i + 1 << endl;
                }
            }
            else
                continue;
        }
    }
}
}
else
{
    cout << -1 << endl;
}