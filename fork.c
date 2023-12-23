main()
{
    for(int i=0;i<2;i++)
        if(!fork()) while(1);
    sleep(20);
}
