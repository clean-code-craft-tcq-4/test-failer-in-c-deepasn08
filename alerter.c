#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

enum environment
{
    Test,
    Prod
};

int networkAlerter(enum environment env, float celcius){
    if(env == 0) return networkAlertStub(celcius);
    else return networkAlerterReal(celcius);
}

int networkAlerterReal(float celcius)
{
    // this method will connect with real devices and decides based on device and input temp
    // for now returning 200
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 200;
}

int networkAlertStub(float celcius)
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok, ok is celcius < 800
    // Return 500 for not-ok, not-ok is celcius >= 800
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(enum environment env, float farenheit)
{
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerter(env,celcius);
    if (returnCode != 200)
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main()
{
    alertInCelcius(0, 400.5);
    assert(alertFailureCount == 0);
    alertInCelcius(0, 303.6);
    assert(alertFailureCount == 0);
    alertInCelcius(0, 1473.8);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
