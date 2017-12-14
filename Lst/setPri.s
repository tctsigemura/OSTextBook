;;  CPU のフラグの値を返すと同時に新しい値に変更
_setPri
        ld      g0,2,sp	; 引数の値を G0 に取り出す
        push    g0	; 新しい状態をスタックに積む
        ld      g0,flag	; 古いフラグの値を返す準備をする
        reti		; reti は FLAG と PC を同時に pop する
