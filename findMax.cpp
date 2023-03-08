void findMax()
{
    int N;
    cin >> N;
    
    int max = -99999, tmp;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        
        if (max < tmp) max = tmp;
    }
    
    cout << max;
}
