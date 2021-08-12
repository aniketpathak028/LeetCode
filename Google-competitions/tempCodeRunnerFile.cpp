unordered_set<float> set;
    set.insert(a);
    set.insert(b);
    set.insert(c);
    set.insert(d);

    int count = set.size();
    ans += 4 - count + 1;