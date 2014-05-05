#include <sys/types.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/module.h>
#include <sys/sysent.h>
#include <sys/kernel.h>
#include <sys/systm.h>
#include <sys/lock.h>
#include <sys/mutex.h>

//------------------system call: setProcessTickets----------------

//1. Declare struct syscall_args{...}
struct setProcessTickets_args {int pid; int tickets;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static int
setProcessTickets(struct thread *td, struct setProcessTickets_args *arg)
{
   /*
    setProcessTickets logic:
    if PID exists, set tickets to such process
    if PID does not exists, return error code (-1)
    */
    
    struct proc *process0;
    process0 = pfind(arg->pid);
    if(process0 == NULL){
        td->td_retval[0] = -1;
        return 0;
    }
    else{
        process0->tickets = arg->tickets; //set process1's tickets with arg's tickets
        td->td_retval[0] = process0->tickets;
        PROC_UNLOCK(process0);
        return 0;
    }

}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent setProcessTickets_sysent = {2, setProcessTickets};

//4. Declare and initialize offset = NO_SYSCALL
static int offset0 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_setProcessTickets(struct module *module, int cmd, void *arg)
{
    int error = 0;
    
    switch (cmd)
    {
        case MOD_LOAD:
            printf("syscall setProcessTickets loaded at %d\n", offset0);
            break;
        case MOD_UNLOAD:
            printf("syscall setProcessTicket unloaded at %d\n", offset0);
            break;
        default:
            error = EINVAL;
            break;
    }
  return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(setProcessTickets, &offset0, &setProcessTickets_sysent, load_setProcessTickets, NULL);



//------------------system call: getProcessTickets----------------

//1. Declare struct syscall_args{...}
struct getProcessTickets_args {int pid;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static int 
getProcessTickets(struct thread *td, struct getProcessTickets_args *arg)
{
    //getProcessTickets logic here
    //if PID exists, get tickets from such process
    //if PID does not exists, return error code (-1)
    struct proc *process1;
    int procTickets;
    process1 = pfind(arg->pid);
    if(process1 == NULL){
        td->td_retval[0] = -1;
        return 0;
    }
    else{
        procTickets = process1->tickets;
        td->td_retval[0] = procTickets;
        PROC_UNLOCK(process1);
        return 0;
    }
    
}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent getProcessTickets_sysent = {1, getProcessTickets};

//4. Declare and initialize offset = NO_SYSCALL
static int offset1 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_getProcessTickets(struct module *module, int cmd, void *arg)
{
   int error = 0;
    
   switch (cmd)
   {
      case MOD_LOAD:
         printf("syscall getProcessTickets loaded at %d\n", offset1);
         break;
      case MOD_UNLOAD:
         printf("syscall getProcessTickets unloaded at %d\n", offset1);
         break;
      default:
         error = EINVAL;
         break;
   }
   return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(getProcessTickets, &offset1, &getProcessTickets_sysent, load_getProcessTickets, NULL);
 

//------------------system call: setSocialInfo----------------
//1. Declare struct syscall_args{...}
struct setSocialInfo_args {int pid; u_int64_t social_info;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static int
setSocialInfo(struct thread *td, struct setSocialInfo_args *arg)
{
 
     //setSocialInfo logic:
     //if PID exists, set social_info to such process
     //if PID does not exists, return error code (-1)
    
    struct proc *process2;
    process2 = pfind(arg->pid);
    if(process2 == NULL){
        td->td_retval[0] = -1;
        return 0;
    }
    else{
        process2->social_info = arg->social_info; //set process's social_info with arg's social_info
        PROC_UNLOCK(process2);
        return 0;
    }
    
}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent setSocialInfo_sysent = {2, setSocialInfo};

//4. Declare and initialize offset = NO_SYSCALL
static int offset2 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_setSocialInfo(struct module *module, int cmd, void *arg)
{
    int error = 0;
    
    switch (cmd)
    {
        case MOD_LOAD:
            printf("syscall setSocialInfo loaded at %d\n", offset2);
            break;
        case MOD_UNLOAD:
            printf("syscall setSocialInfo unloaded at %d\n", offset2);
            break;
        default:
            error = EINVAL;
            break;
    }
    return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(setSocialInfo, &offset2, &setSocialInfo_sysent, load_setSocialInfo, NULL);

//------------------system call: getSocialInfo----------------

//1. Declare struct syscall_args{...}
struct getSocialInfo_args {int pid;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static u_int64_t
getSocialInfo(struct thread *td, struct getSocialInfo_args *arg)
{
 
     //getSocialInfo logic:
     //if PID exists, get social_info from such process
     //if PID does not exists, return error code (-1)
    
    struct proc *process0;
    u_int64_t social_info;
    process0 = pfind(arg->pid);
    if(process0 == NULL){
        td->td_retval[0] = -1;
        return 0;
    }
    else{
        social_info = process0->social_info; //get process's social_info
        td->td_retval[0] = social_info;  //will just truncate
        PROC_UNLOCK(process0);
        return 0;
    }
    
}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent getSocialInfo_sysent = {1, getSocialInfo};

//4. Declare and initialize offset = NO_SYSCALL
static int offset3 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_getSocialInfo(struct module *module, int cmd, void *arg)
{
    int error = 0;
    
    switch (cmd)
    {
        case MOD_LOAD:
            printf("syscall getSocialInfo loaded at %d\n", offset3);
            break;
        case MOD_UNLOAD:
            printf("syscall getSocialInfo unloaded at %d\n", offset3);
            break;
        default:
            error = EINVAL;
            break;
    }
    return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(getSocialInfo, &offset3, &getSocialInfo_sysent, load_getSocialInfo, NULL);



//------------------system call: setLotteryMode----------------

//1. Declare struct syscall_args{...}
struct setLotteryMode_args {int mode;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static int
setLotteryMode(struct thread *td, struct setLotteryMode_args *arg)
{
 
     //setLotteryMode logic:

    lottery_mode = arg->mode;
    td->td_retval[0] = 0;
    
    return 0;
    
}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent setLotteryMode_sysent = {1, setLotteryMode};

//4. Declare and initialize offset = NO_SYSCALL
static int offset4 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_setLotteryMode(struct module *module, int cmd, void *arg)
{
    int error = 0;
    
    switch (cmd)
    {
        case MOD_LOAD:
            printf("syscall setLotteryMode loaded at %d\n", offset4);
            break;
        case MOD_UNLOAD:
            printf("syscall setLotteryMode unloaded at %d\n", offset4);
            break;
        default:
            error = EINVAL;
            break;
    }
    return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(setLotteryMode, &offset4, &setLotteryMode_sysent, load_setLotteryMode, NULL);

//------------------system call: getLotteryMode----------------

//1. Declare struct syscall_args{...}
//struct setLotteryMode_args {int mode;};

//2. Define syscall(struct thread *td, struct syscall_args *arg){...}
static int
getLotteryMode(struct thread *td, void *arg)
{
     
    td->td_retval[0] = lottery_mode;
    return 0;
    
}

//3. Declare and initialize struct sysent syscall_sysent = {arguments #, syscall}
static struct sysent getLotteryMode_sysent = {0, getLotteryMode};

//4. Declare and initialize offset = NO_SYSCALL
static int offset5 = NO_SYSCALL;

//5. Define load_syscall(struct module *module, int cmd, void *arg)
static int
load_getLotteryMode(struct module *module, int cmd, void *arg)
{
    int error = 0;
    
    switch (cmd)
    {
        case MOD_LOAD:
            printf("syscall getLotteryMode loaded at %d\n", offset5);
            break;
        case MOD_UNLOAD:
            printf("syscall getLotteryMode unloaded at %d\n", offset5);
            break;
        default:
            error = EINVAL;
            break;
    }
    return error;
}

//6. Call SYSCALL_MODULE(syscall, &offset, &syscall_sent, load_syscall, NULL)
SYSCALL_MODULE(getLotteryMode, &offset5, &getLotteryMode_sysent, load_getLotteryMode, NULL);





