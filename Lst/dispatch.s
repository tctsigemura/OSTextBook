; 現在のプロセス(curProc)がCPUを解放する．その後，新プロセスへディスパッチする．
_yield                          ; 高級言語からは yield() 関数として呼出す．
        ;--- G13(SP)以外の CPU レジスタと FLAG をカーネルスタックに退避 ---
        push    g0              ; FLAG の保存場所を準備する
        push    g0              ; G0 を保存
        ld      g0,flag         ; FLAG を上で準備した位置に保存
        st      g0,2,sp         ;
        push    g1              ; G1 を保存
        push    g2              ; G2 を保存
        push    g3              ; G3 を保存
        ...
        ...                     ; G4 から G10も同様に保存する
        ...
        push    g11             ; G11 を保存
        push    fp              ; フレームポインタ(G12)を保存
        push    usp             ; ユーザモードスタックポインタ(G14)を保存
        ;------- G13(SP)を PCB に保存 ---------------------------
        ld      g1,_curProc     ; G1 <- curProc
        st      sp,0,g1         ; [G1+0] は PCB の sp フィールド
        ;------- [curProc の magic フィールド]をチェック ---------
        ld      g0,30,g1        ; [G1+30] は PCB の magic フィールド
        cmp     g0,#0xabcd      ; P_MAGIC と比較、一致しなければ
        jnz     .stkOverFlow    ; カーネルスタックがオーバーフローしている
;
; 最優先のプロセス（readyQueueの先頭プロセス）へディスパッチする．
_dispatch                       ; 高級言語からは dispatch() 関数として呼出す．
        ;-------- 次に実行するプロセスの G13(SP)を復元 ----------
        ld      g0,_readyQueue  ; 実行可能列の番兵のアドレス
        ld      g0,28,g0        ; [G0+28] は PCB の next フィールド(先頭の PCB)
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
