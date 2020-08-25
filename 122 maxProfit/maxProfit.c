int maxProfit(int* prices, int pricesSize){
int i =0;
int sum =0;

    if(pricesSize==0)
    {
        return 0;
    }

    for(i=0;i<pricesSize-1;i++)
    {
        if(prices[i+1]>prices[i])
        {
            sum = sum+ prices[i+1] -prices[i];
        }
    }

    return sum ;
}
