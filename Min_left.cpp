vector<int> st, vec(n);
st.pb(0);
    for (int i = 1; i < n + 2; i++) {
        while (vec[st.back()] > vec[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
