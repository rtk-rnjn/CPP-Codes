
        // adding number of days in a month
        for (int j = 1; j <= days; j++) {
            printf("%5d", j);
            
            // adding new line after every 7 days
            if (++k > 6) {
                k = 0;
                cout << endl;
            }
        }

        // check if new line is requ