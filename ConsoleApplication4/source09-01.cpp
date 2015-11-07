
    sort(v.begin(), v.end());
    for (i = v.begin(); i < v.end() - 1; i++)
        for (j = v.end() - 1; j > i; j--) {
            if (binary_search(v.begin(), v.end(), Point(j->x, i->y)) &&
                binary_search(v.begin(), v.end(), Point(i->x, j->y)) &&
                Point(i->x, i->y) < Point(j->x, i->y) &&
                Point(j->x, i->y) < Point(i->x, j->y))
                nTotalNum++;
        }
    cout << nTotalNum << endl;
