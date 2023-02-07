data segment
    array  dw 25000 dup(?)
    n      dw ?
    tmp    dw ?
    string db 6, ?, 6 dup('$')
    tmp_ip dw ?
    l      dw ?
    r      dw ?
    tmp1   dw ?
    tmp2   dw ?
data ends
code segment
               assume cs:code, ds:data

    ;read a number, store in tmp
input proc

               push   ax
               push   bx
               push   cx
               push   dx
               mov    ax, 0
               mov    tmp, ax
               mov    ah, 0ah
               lea    dx, string
               int    21h



               mov    dx, 1
               mov    cx, 10
               mov    bx, 1
               mov    bl, string[bx]

               and    bh, 0
               inc    bx
    calc:      
               mov    al, string[bx]
               cbw
               sub    ax, 30h

               push   dx
               mul    dx
               pop    dx

               add    ax, tmp
               mov    tmp, ax
               mov    ax, dx
               mul    cx
               mov    dx, ax
               dec    bx
               cmp    bx, 1
               jg     calc

               pop    dx
               pop    cx
               pop    bx
               pop    ax

               ret
input endp
    ;\r\n
CRLF proc
               push   dx
               push   ax
               mov    ah, 2
               mov    dl, 13
               int    21h
               mov    dl, 10
               int    21h
               pop    ax
               pop    dx
               ret
CRLF endp
    ;output the number in tmp
output proc
               push   ax
               push   bx
               push   cx
               push   dx

               mov    ax, tmp
               mov    dx, 0
               mov    bx, 10
               mov    cx, 0
    rep4:      
               inc    cx
               div    bx
               push   dx
               mov    dx, 0
               cmp    ax, 0
               jne    rep4

    rep5:      
               pop    ax
               mov    ah, 2
               add    al, 30h
               mov    dl, al
               int    21h

               loop   rep5

               pop    dx
               pop    cx
               pop    bx
               pop    ax

               ret

output endp

quick_sort proc
               pop    tmp_ip

               pop    dx                  ;r
               pop    ax                  ;l

               push   tmp_ip              ; push ip back into stack
               
               mov    l, ax
               mov    r, dx
               cmp    ax, dx
               jge    return              ;if(l >= r) return;

               mov    bx, 0
               add    bx, ax
               add    bx, dx
               shr    bx, 1
               and    bx, 0fffeh
               mov    cx, array[bx]       ; int cx = array[l + r >> 1]

               sub    ax, 2               ; int ax = l - 1;
               add    dx, 2               ; int dx = r + 1;

    rep6:      
               add    ax, 2               ; do ax ++;
               xchg   ax, bx
               cmp    array[bx], cx
               xchg   ax, bx
               jl     rep6                ;while(array[ax] < cx)
    rep7:      
               sub    dx, 2               ; do dx --;
               xchg   dx, bx
               cmp    array[bx], cx
               xchg   dx, bx
               jg     rep7                ;while(array[dx] > cx);

               cmp    ax, dx
               jl     rep8                ; if(ax < dx) swap(array[ax], array[dx];
               jmp    return1             ;else break;

    rep8:      
               push   cx
               xchg   ax, bx
               mov    cx, array[bx]
               mov    tmp1, cx
               xchg   ax, bx
               xchg   bx, dx
               mov    cx, array[bx]
               mov    tmp2, cx
               mov    cx, tmp1
               xchg   cx, array[bx]
               xchg   bx, dx
               xchg   ax, bx
               mov    cx, tmp2
               xchg   cx, array[bx]
               xchg   ax, bx
               pop    cx                  ; swap(array[ax], array[dx]);
               jmp    rep6                ; while(ax < dx);

    return1:   
               push   dx
               push   r

               push   l
               push   dx
               call   quick_sort          ; quick_sort(l, dx)

               pop    r
               pop    dx
               add    dx, 2
               push   dx
               push   r
               call   quick_sort          ; quick_sort(dx+1, r)
    return:    

               ret
quick_sort endp

    start:     
               mov    ax, data
               mov    ds, ax
               call   input               ; read the number n which means the number of the array
               call   CRLF
               mov    cx, tmp
               mov    n, cx
               mov    bx, 0
    rep2:      
               call   input
               call   CRLF
               mov    dx, tmp
               mov    array[bx], dx
               add    bx, 2
               loop   rep2                ; read n numbers for array

               mov    ax, 0
               push   ax
               mov    ax, n
               shl    ax, 1
               sub    ax, 2
               push   ax                  ; l = 0, r = n - 1;
               call   quick_sort

               mov    cx, n
               mov    bx, 0
               call   CRLF
    rep3:      
               mov    dx, array[bx]       ; output the array after sorted
               add    bx, 2
               mov    tmp, dx
               call   output
               call   CRLF
               loop   rep3
               mov    ax, 4c00h
               int    21h
code ends
end start