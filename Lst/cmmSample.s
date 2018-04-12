_x      DW        1       // int x = 1;
_y      WS        1       // int y;
_main   PUSH      FP      // void main() {
        LD        FP,SP
        PUSH      G3      //   int z;
        PUSH      G4      //   char *p;
        LD        G0,#10  //
        PUSH      G0      //
        CALL      _malloc //   p = malloc(10);
        ADD       SP,#2   //
        LD        G4,G0   // 
        POP       G4
        POP       G3
        POP       FP
        RET               // }
