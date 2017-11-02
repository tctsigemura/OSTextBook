;
; 最優先のプロセス（readyQueueの先頭プロセス）へディスパッチする．
_dispatch                       ; 高級言語からはdispatch()関数として呼出す
        ;-------- 次に実行するプロセスの G13(SP)を復元 ----------
        ld      g0,_readyQueue  ; 実行可能列の番兵のアドレス
        ld      g0,28,g0        ; [G0+28]はPCBのnextフィールド(先頭のPCB)
        st      g0,_curProc     ; 現在のプロセス(curProc)に設定する
        ld      sp,0,g0         ; PCB から SP を取り出す
        ;-------- G13(SP)以外の CPU レジスタを復元 -----------
        pop     usp             ; ユーザモードスタックポインタ(G14)を復元
        pop     fp              ; フレームポインタ(G12)を復元
        pop     g11             ; G11 を復元
        ...
        ...                     ; G10 から G4も同様に復元する
        ...
        pop     g3              ; G3 を復元
        pop     g2              ; G2 を復元
        pop     g1              ; G1 を復元
        pop     g0              ; G0 を復元
        ;------------- PSW(FLAG と PC)を復元 -----------------
        reti                    ; RETI 命令で一度に POP して復元する
; 