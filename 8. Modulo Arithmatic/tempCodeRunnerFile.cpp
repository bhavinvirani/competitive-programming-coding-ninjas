ll ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans * i) % MOD;
        }