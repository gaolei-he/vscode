main()
{
    for(int i=0;i<16;i++)
        if(!fork()) while(1){sleep(1);}
}
