; 現在のプロセス(curProc)がCPUを解放する．次に新プロセスへディスパッチする．
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
