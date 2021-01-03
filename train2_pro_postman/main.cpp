#include <stdio.h>
#include <iostream>

using namespace std;

struct PosMan {
    long long int x;
    long long int m;
};

long long int minRoad(PosMan a[], int begin, int end, int k) {
    int temp = end, remaining;
    long long int time = 0;

    /*from end to begin*/
    while (temp >= begin) {

        /*get mail => remaining = k */
        remaining = k;
        /*
        if k < a[temp] => go to temp and return company => 2 times distance
        after that, postman is at company and number of mails currently smaller than k
        */
        time += 2 * a[temp].x * (a[temp].m / k);
        a[temp].m -= k * (a[temp].m / k);

        /*if remaining mails at temp is zero -> goto temp - 1 postion*/
        if (a[temp].m == 0 && temp > begin) {
            time += a[temp - 1].x;
        } else

        /*if remaining mails at temp isn't zero -> send mail to temp and goto temp - 1*/
        if (a[temp].m != 0 && temp > begin) {
            remaining -= a[temp].m;
            time += a[temp].x + a[temp].x - a[temp - 1].x;
        } else

        /* if remaining mails at temp is zero
            and postion at nearest company
            => don't need send*/
        if (a[temp].m == 0 && temp == begin) {
            break;
        } else
        /* if remaining mails at temp isn't zero and
           postion is neareat comany
           => send mails and return company*/
        {
            time += 2 * a[temp].x;
            break;
        }
        /*go to temp - 1*/
       temp--;

        /* if a[temp].m < remaining => send and go to temp - 1*/
        while (a[temp].m <= remaining && temp > begin) {
            remaining -= a[temp].m;
            temp--;
            time += a[temp + 1].x - a[temp].x;
        }

        /* if a[temp].m <= remaining
        and postion at nearest company
        => send mails and return company */
        if (temp == begin && a[temp].m <= remaining) {
            time += a[temp].x;
            break;
        } else {
            a[temp].m -= remaining;
            time += a[temp].x;
        }
    }

    return time;
}

void swap(PosMan *first, PosMan *second) {
    PosMan *temp;
    temp = first;
    first = second;
    second = temp;
}

int main() {
    long long int n, k, tg, remaining, i, time = 0, x, m;
    PosMan posMan[1000], temp, temp1;

    /*declarate*/
    cin >> n >> k;

    for (i = 0; i < n; i++) {
        cin >> temp.x >> temp.m;
        posMan[i] = temp;
    }

    /*sort from small to large*/
    for (i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (posMan[i].x >= posMan[j].x) {
                swap(posMan[i], posMan[j]);
            }
        }

    }

    // find coordinate distinguish between positive and negative numbers
    int vt;
    for (i = 0; i < n; i++)
        if (posMan[i].x >=0) {
            vt = i;
            break;
        } else {
            posMan[i].x = - posMan[i].x;
        }

    tg = 0;

    /* change negative numbers to positive number
        sort from small to large*/
    while (tg < vt/2) {
        temp = posMan[tg];
        posMan[tg] = posMan[vt - tg - 1];
        posMan[vt - tg -1] = temp;
        tg++;
    }

    time = minRoad(posMan, vt, n - 1, k) + minRoad(posMan, 0, vt - 1, k);
    cout << time;
}
