#include <stdio.h>
#include <stdlib.h>

/* use void as data type because these function does not need to return a value */
/* create function to store codes that contain plan details and benefits so that these codes can be reused easily in other program */
void insurance130()
{
    printf("INSURANCE130\n\n-Hospitalisation and Surgical Benefits-\nRoom Charges : RM120/day\nIntensive Care Unit (ICU) Charges : RM250/day\nHospital Supplies and Services : As charged. Subject to approval by HELPMediLife.\nSurgical Fees : As charged. Subject to approval by HELPMediLife.\nOther Fees : As charged. Subject to approval by HELPMediLife.\n\n-Details-\nMonthly Fee : RM130\nAnnual Claim Limit : RM100,000\nLifetime Claim Limit : RM500,000");
}

void insurance160()
{
    printf("INSURANCE160\n\n-Hospitalisation and Surgical Benefits-\nRoom Charges : RM150/day\nIntensive Care Unit (ICU) Charges : RM400/day\nHospital Supplies and Services : As charged. Subject to approval by HELPMediLife.\nSurgical Fees : As charged. Subject to approval by HELPMediLife.\nOther Fees : As charged. Subject to approval by HELPMediLife.\n\n-Details-\nMonthly Fee : RM160\nAnnual Claim Limit : RM120,000\nLifetime Claim Limit : RM600,000");
}

void insurance180()
{
    printf("INSURANCE180\n\n-Hospitalisation and Surgical Benefits-\nRoom Charges : RM200/day\nIntensive Care Unit (ICU) Charges : RM700/day\nHospital Supplies and Services : As charged. Subject to approval by HELPMediLife.\nSurgical Fees : As charged. Subject to approval by HELPMediLife.\nOther Fees : As charged. Subject to approval by HELPMediLife.\n\n-Details-\nMonthly Fee : RM180\nAnnual Claim Limit : RM200,000\nLifetime Claim Limit : RM2,000,000");
}

/* create function here to divide the program into smaller part so is easier to see */
/* the while loop is to ensure user key in valid input so program can know which plan he/she choose */
char CheckplanA(char planchoice)
{
    while (planchoice!='Y' && planchoice!='Z')
    {
        printf("\nYour input is invalid.\nWhich plan you want to choose?\n*Note : Choose only one plan*\n");
        scanf(" %c", &planchoice);
    }
    return planchoice;
}

char CheckplanB(char planchoice)
{
    while (planchoice!='X' && planchoice!='Y' && planchoice!='Z')
    {
        printf("\nYour input is invalid.\nWhich plan you want to choose?\n*Note : Choose only one plan*\n");
        scanf(" %c", &planchoice);
    }
    return planchoice;
}

int main ()
{
    int age;
    char proceedplanselection, plananswer, claimanswer, name[100], gender[20], job[100], number[50], email[1000], address[1000], health[1000];

    printf("Thank you for your interest in the HELPMediLife Health Insurance Plan.\nIn order for us to identify the plans that you are eligible for, can we first know what is your age?\nAge : ");
    scanf("%d", &age);    //get input (age) from user to check his or her eligibility

    if (age<15 || age>54)
    {
        printf("\nSorry to inform you that your age is not eligible for the HELPMediLife Health Insurance Plan.");
        exit(0);    //to terminate the entire program immediately because it is useless to execute the rest of the program since these ages are not eligible for any plans
    }
    else
    {
        printf("\nBelow are the plans that you are eligible for and their details :\n\n\n");

        /* execute the code only if the condition is true */
        if (age>=15 && age<=20)
        {
            insurance180();     //call the function
            printf("\n\n-----------------------------------------------------------------------------------------\n\n*Note : All subscribers are eligible for Hospital Supplies and Services, Surgical Fees and other fees of any amount as long the charges are within the coverage amount of their plan.*");
        }
        else if (age>=21 && age<=40)
        {
            insurance160();
            printf("\n\n------------------------------------------------------------------------------------------\n\n");
            insurance180();
            printf("\n\n------------------------------------------------------------------------------------------\n\n*Note : All subscribers are eligible for Hospital Supplies and Services, Surgical Fees and other fees of any amount as long the charges are within the coverage amount of their plan.*");
        }
        else
        {
            insurance130();
            printf("\n\n------------------------------------------------------------------------------------------\n\n");
            insurance160();
            printf("\n\n------------------------------------------------------------------------------------------\n\n");
            insurance180();
            printf("\n\n------------------------------------------------------------------------------------------\n\n*Note : All subscribers are eligible for Hospital Supplies and Services, Surgical Fees and other fees of any amount as long the charges are within the coverage amount of their plan.*");
        }

        /* in case user only want to take a look at the plan details and benefits and has not decide to buy a plan */
        printf("\n\nDo you want to proceed to the next step (selection of plan and claim limit)? (Y/N)\n");
        scanf(" %c", &proceedplanselection);

        while (proceedplanselection!='Y' && proceedplanselection!='N')      // repeat this section of code for an infinite time until user key in valid input (Y/N)
        {
            printf("\nYour input is invalid.\nDo you want to proceed to the next step (selection of plan and claim limit)? (Y/N)\n");
            scanf(" %c", &proceedplanselection);
        }

        if (proceedplanselection == 'Y')
        {
            if (age>=15 && age<=20)
            {
                printf("\n\nWhich types of claim limit that you want to subscribe? (Your current plan: Insurance180)");
                /* there is only one plan (Insurance180) is eligible for age 15 - 20 */
            }
            else if (age>=21 && age<=40)
            {
                printf("\n\n\nWhich plan you want to choose?\t*Note : Choose only one plan*\nY - Insurance160\tZ - Insurance180\n");
                scanf(" %c", &plananswer);
                plananswer = CheckplanA(plananswer); // call the function
            }
            else
            {
                printf("\n\n\nWhich plan you want to choose?\t*Note : Choose only one plan*\nX - Insurance130\tY - Insurance160\tZ - Insurance180\n");
                scanf(" %c", &plananswer);
                plananswer = CheckplanB(plananswer);
            }
            /* required scanf to get user input(plan choice) */

            /* this if else statement is to show the user's current plan */
            if (plananswer == 'X')
                printf("\n\n\nWhich types of claim limit that you want to subscribe? (Your current plan: Insurance130)\n");

            else if (plananswer == 'Y')
                printf("\n\n\nWhich types of claim limit that you want to subscribe? (Your current plan: Insurance160)\n");

            else
                printf("\n\n\nWhich types of claim limit that you want to subscribe? (Your current plan: Insurance180)\n");

            printf("A - Annual Claim Limit\tL - Lifetime Claim Limit");
            printf("\n\n*Note : You can only subscribe to either one.\nFor Annual Claim Limit, you can claim up to the amount stated in the -Details- but until the age of 60 only.\nFor Lifetime Claim Limit, you can claim for life but until all the stated amount (as in -Details-) is exhausted.*");
            printf("\n\nTypes of Claim Limit :  ");
            scanf(" %c", &claimanswer);

            while (claimanswer!='A' && claimanswer!='L')    // repeat this section of code for an infinite time until user key in valid input (A/L)
            {
                printf("Your input is invalid.\n\nTypes of Claim Limit :  ");
                scanf(" %c", &claimanswer);
            }

            /* use fgets() to read a line of string (even with spaces) */
            printf("\n\n\nThank you for selecting HELPMediLife Health Insurance Plan. Please provide some of your basic information.\n\n");
            getchar();      //add a getchar() after scanf() to read an extra newline
            printf("Name : ");
            fgets(name, sizeof(name), stdin);
            printf("Gender (Male / Female) : ");
            fgets(gender, sizeof(gender), stdin);
            printf("Occupation : ");
            fgets(job, sizeof(job), stdin);
            printf("Contact number : ");
            fgets(number, sizeof(number), stdin);
            printf("Email address : ");
            fgets(email, sizeof(email), stdin);
            printf("Correspondence address : ");
            fgets(address, sizeof(address), stdin);
            printf("Health history : ");
            fgets(health, sizeof(health), stdin);

            printf("\n\nHere are your personal information and your subscribed plan details and benefits\n********************************************************************************************\n\n");
            printf("Name : %s", name);
            printf("Gender : %s", gender);
            printf("Occupation : %s", job);
            printf("Contact number : %s", number);
            printf("Email address : %s", email);
            printf("Correspondence address : %s", address);
            printf("Health history : %s", health);

            /* use if else statement to check which plan is selected by the user and then display the plan details and benefit */
            if (age>=15 && age<=20)
            {
                printf("\n\nPlan : ");
                insurance180();
            }
            else
            {
                if (plananswer == 'X')
                {
                    printf("\n\nPlan : ");
                    insurance130();
                }
                else if (plananswer == 'Y')
                {
                    printf("\n\nPlan : ");
                    insurance160();
                }
                else
                {
                    printf("\n\nPlan : ");
                    insurance180();
                }
            }

            /* use if else statement to check which claim is subscribed by the user and then display his/her choice of claim */
            if (claimanswer == 'A')
            {
                printf("\n(You only subscribed to Annual Claim Limit.\nYou can claim up to the amount stated in the -Details- but until the age of 60 only.)");
            }
            else
            {
                printf("\n(You only subscribed to Lifetime Claim Limit.\nYou can claim for life but until all the stated amount (as in -Details-) is exhausted.)");
            }
            printf("\n\n********************************************************************************************\n");
        }

        else
        {
            printf("\n\nThank you and have a great day!");
        }
    }
}
