rec(0) {    
    rec(1){
        rec(2){
            rec(3){
                printArray(s); // 0 0 0
            }

            s[2] = 1;

            rec(3){                
                printArray(s); // 0 0 1                
            }

            s[2] = 0;
        }

        s[1] = 1

        rec(2) {
            rec(3){
                printArray(s) // 0 1 0
            }

            s[2] = 1;
            rec(3) {
                printArray(s) // 0 1 1
            }
            s[2] = 0
        }
        
        s[1] = 0
    }

    s[i] = 1;

    rec(1){
        rec(2){
            rec(3){
                printArray(s); // 1 0 0
            }

            s[2] = 1;

            rec(3){                
                printArray(s); // 1 0 1                
            }

            s[2] = 0;
        }

        s[1] = 1

        rec(2) {
            rec(3){
                printArray(s) // 1 1 0
            }

            s[2] = 1;
            rec(3) {
                printArray(s) // 1 1 1
            }
            s[2] = 0
        }
        
        s[1] = 0
    }
    s[i] = 0;
}



void rec(int i) {
    if(i == n){
        printArray(s);
        return;
    }
    
    rec(i+1);
    s[i] = 1;
    
    rec(i+1);
    s[i] = 0;
}