#include <math.h>
#include "../../inc/ProgramHandler.h"
#include "../../inc/FileHandler.h"
#include "../../inc/Helper.h"
#include "../../inc/MessagingHandler.h"
#include "gtest/gtest.h"

TEST(MessagingHandlerTest, sendReceivex2Message)
{
  ProgramHandler t1("./firtsProcess");
	ASSERT_EQ(t1.startApp(), 1);
  MessagingHandler mh("/queueTest",1);
  std::string messageToSend = "messageToSend";
  std::string messageToReceive;
  mh.sendMessage(messageToSend,0);
  while(!mh.receiveMessage(messageToReceive))
  {
	  ASSERT_EQ(messageToReceive, "messageToReceive");
  }
  messageToSend = "messageToSend2";
  messageToReceive;
  mh.sendMessage(messageToSend,0);
  while(!mh.receiveMessage(messageToReceive))
  {
	  ASSERT_EQ(messageToReceive, "messageToReceive2");
  }
  t1.stop(); 
}


TEST(MessagingHandlerTest, sendReceiveMessage)
{
  ProgramHandler t1("./firtsProcess");
	ASSERT_EQ(t1.startApp(), 1);
  MessagingHandler mh("/queueTest",1);
  std::string messageToSend = "messageToSend";
  std::string messageToReceive;
  mh.sendMessage(messageToSend,0);
  while(!mh.receiveMessage(messageToReceive))
  {
	  ASSERT_EQ(messageToReceive, "messageToReceive");
  }
  t1.stop(); 
}

TEST(MessagingHandlerTest, sendReceiveMessageLongerThan100)
{
  ProgramHandler t1("./secondProcess");
	ASSERT_EQ(t1.startApp(), 1);
  MessagingHandler mh("/queueTest2",1);
  std::string messageToSend = "321";
  std::string messageToReceive;
  mh.sendMessage(messageToSend,0);
  while(!mh.receiveMessage(messageToReceive))
  {
	  ASSERT_EQ(messageToReceive, "123");
  }
  t1.stop(); 
}

TEST(HelperTest, verifyPID)
{
	FileHandler fh("fileContainingPID.txt");
  ProgramHandler t("./pid");
	ASSERT_EQ(t.startApp(), 1);
	pid_t pid = Helper::getPID("./pid");

  t.stop();
	ASSERT_TRUE(fh.doesFileExist("fileContainingPID.txt", 1));
  std::string pid_s = fh.readFileToString();

  fh.removeFile();

  ASSERT_EQ(pid, atoi(pid_s.c_str()));
  
}


TEST(FileHandlerTest, OpenExistingFileTest) { 
	FileHandler fh("fileForTest.txt");
  ASSERT_TRUE(fh.openFile());
}

TEST(FileHandlerTest, OpenNonExistingFileTest) { 
  FileHandler fh("fileDoesNotExist.txt");
  ASSERT_FALSE(fh.openFile());
}

TEST(FileHandlerTest, ReadFromFileTest) { 
	FileHandler fh("fileForTest.txt");
  ASSERT_TRUE(fh.openFile());
	std::string stringToCompare = "Testing123\nHello\n";
	ASSERT_EQ(fh.readFileToString(), stringToCompare);
}

TEST(FileHandlerTest, CreateRemoveFileTest) { 
	FileHandler fh("fileToBeCreated.txt");
  ASSERT_FALSE(fh.doesFileExist("fileToBeCreated.txt", 1));
  fh.createFile();

  ASSERT_TRUE(fh.doesFileExist("fileToBeCreated.txt", 1));
	fh.removeFile();
  ASSERT_FALSE(fh.doesFileExist("fileToBeCreated.txt", 1));
}

TEST(ProgramHandlerTest, StartStopTest) { 

  ProgramHandler t("./program");
  ASSERT_FALSE(t.isProgramRunning());

  ASSERT_EQ(t.startApp(), 1);
	ASSERT_TRUE(t.isProgramRunning());
	t.stop();
  //ASSERT_TRUE(t.stop());
	ASSERT_FALSE(t.isProgramRunning());
}

TEST(ProgramHandlerTest, PerformRestart) { 

  ProgramHandler t("./program");
  ASSERT_FALSE(t.isProgramRunning());

  ASSERT_EQ(t.startApp(), 1);
	ASSERT_TRUE(t.isProgramRunning());
	ASSERT_NE(t.performRestart(), -1);
	ASSERT_TRUE(t.isProgramRunning());
	t.stop();
	ASSERT_FALSE(t.isProgramRunning());
}
 
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
