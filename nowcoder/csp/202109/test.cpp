#include <bits/stdc++.h>
static unsigned long next = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void) {
    next = next * 1103515245 + 12345;
    return((unsigned)(next/65536) % 32768);
}
int main() {
    std::set<unsigned long> st;
    st.insert(1);
    while(true) {
        myrand();
        if(st.count(next)) {
            std::cout << st.size() << std::endl;
            break;
        }
        st.insert(next);
    }

}