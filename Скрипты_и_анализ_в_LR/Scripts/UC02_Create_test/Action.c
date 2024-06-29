Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not/A)Brand\";v=\"8\", \"Chromium\";v=\"126\", \"Microsoft Edge\";v=\"126\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	lr_start_transaction("UC02_TR01_login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2024-06-17T19:36:21.848Z");
	
	web_reg_save_param_ex(
      "ParamName=token",
      "LB=",
      "RB=\n",
      SEARCH_FILTERS,
      "Scope=Headers",
      "HeaderNames=Authorization",
      LAST);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	web_add_auto_header("Authorization", "Bearer {token}");

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_regexp(
		"ParamName=token2",
		"RegExp=boomq_auth=(.*)",
		SEARCH_FILTERS,
		"Scope=HEADERS",
		"HeaderNames=set-cookie",
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=13", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_auto_header("Authorization",
		"Bearer {token2} ");

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_TR01_login",LR_AUTO);

	lr_think_time(rand()%10 + 5);

	lr_start_transaction("UC02_TR02_tests");

	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC02_TR02_tests",LR_AUTO);

	lr_start_transaction("UC02_TR03_create_new_test");

	web_add_auto_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(rand()%10 + 10);

	web_add_header("Sec-GPC", 
		"1");

	web_custom_request("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"{TestName}_{NumTest}\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{\"testRunnerIds\":[{generator}]},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"95724dee-327c-4244-8490-d74b1d2e599b\",\"label\":\"New group {randomGroup}\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\""
		"typeDisplayName\":\"\",\"threadGroupElements\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"POST\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"{path}\",\"port\":\"{port}\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"{host}\",\"headers\":{\"Content-Type\":\""
		"application/json\"},\"queryParameters\":[],\"body\":\"{\\n \\\"message\\\": \\\"message_{message}\\\",\\n \\\"username\\\": \\\"user_{userNameMessage}\\\"\\n }\",\"bodyParameters\":[]},\"timerList\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_f8adf57b-a9ea-4bc0-8d65-46e0d08c2916\",\"id\":\"f8adf57b-a9ea-4bc0-8d65-46e0d08c2916\",\"durationMs\":22000,\"enabled\":true}],\"label\":\"{URL}\",\"id\":\"755ba81c-585d-4065-b6fa-3a0c67025769\",\""
		"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"bcc19411-d40d-4e18-965b-29931ba720c3\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\""
		"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"a86eef08-fbf6-4389-8e4b-9d044cdd5904\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"742a72ef-a123-4eee-8deb-18a376049472\""
		",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"cf73e401-00c7-4208-ae13-78c3d62b4bf3\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":{VUnum},\"rampDownMs\":{rampDownMs},\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":{rampUpMs},\"stepLengthMs\":{stepLengthMs},\"stepCount\":1},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\""
		"boomq_timer_7e3dcacc-74d9-43f5-bce5-1d18a22fd3b1\",\"id\":\"7e3dcacc-74d9-43f5-bce5-1d18a22fd3b1\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":{totalDuration}}",  
		EXTRARES, 
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);
/*	
	"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"untitled_test_20:08\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{\"testRunnerIds\":[1]},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"95724dee-327c-4244-8490-d74b1d2e599b\",\"label\":\"New group 122222\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\""
		"typeDisplayName\":\"\",\"threadGroupElements\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"POST\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"/api/messages/send/kafka-topic-group-3\",\"port\":\"48998\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"77.50.236.215\",\"headers\":{\"Content-Type\":\""
		"application/json\"},\"queryParameters\":[],\"body\":\"{\\n \\\"message\\\": \\\"58dgtf565j8547f64ke7\\\",\\n \\\"username\\\": \\\"16.06.2024\\\"\\n }\",\"bodyParameters\":[]},\"timerList\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_f8adf57b-a9ea-4bc0-8d65-46e0d08c2916\",\"id\":\"f8adf57b-a9ea-4bc0-8d65-46e0d08c2916\",\"durationMs\":22000,\"enabled\":true}],\"label\":\"http://77.50.236.215:48998/api/messages/send/kafka-topic-group-3\",\"id\":\"755ba81c-585d-4065-b6fa-3a0c67025769\",\""
		"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"bcc19411-d40d-4e18-965b-29931ba720c3\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\""
		"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"a86eef08-fbf6-4389-8e4b-9d044cdd5904\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"742a72ef-a123-4eee-8deb-18a376049472\""
		",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"cf73e401-00c7-4208-ae13-78c3d62b4bf3\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":3,\"rampDownMs\":60000,\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":60000,\"stepLengthMs\":3600000,\"stepCount\":1},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\""
		"boomq_timer_7e3dcacc-74d9-43f5-bce5-1d18a22fd3b1\",\"id\":\"7e3dcacc-74d9-43f5-bce5-1d18a22fd3b1\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":3720}", 
		
*/		
/*		
		
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"{TestName}_{NumTest}\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{\"testRunnerIds\":[2]},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"92bb7e86-a036-41f8-bd6e-0d7a8c7044b9\",\"label\":\"New group {randomGroup}\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\""
		"\",\"threadGroupElements\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"POST\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"{path}\",\"port\":\"{port}\",\"protocol\":\"https\",\"search\":\"?\",\"serverName\":\"{host}\",\"headers\":{\"Content-Type\":\"application/json\"},\""
		"queryParameters\":[],\"body\":\"{\\n \\\"message\\\": \\\"{message}\\\",\\n \\\"username\\\": \\\"{userNameMessage}\\\"\\n }\",\"bodyParameters\":[]},\"timerList\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_b827851e-0c94-4ead-965f-ea563069b0e7\",\"id\":\"b827851e-0c94-4ead-965f-ea563069b0e7\",\"durationMs\":22000,\"enabled\":true}],\"label\":\"{URL}\",\"id\":\"9d42fbe5-4856-4b97-a743-072387cfc5c9\",\"type\":\"SAMPLER\",\""
		"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"b34313c1-fa3f-440f-9784-d2c9402e6705\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\""
		"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"ea95cd9c-2af5-4d83-af1d-5ca2dc2b2357\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\"Http header manager\",\"id\":\"6bfea529-9abf-4d95-9424-b9781399969e\",\"type\":\""
		"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"0a66bcd6-d659-4371-8c1e-0a6afb191d43\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":{VUnum},\"rampDownMs\":60000,\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":60000,\"stepLengthMs\":3600000,\"stepCount\":1},\"timers\":[{\"timerType\":\"CONSTANT\",\"label\":\""
		"boomq_timer_8fc49615-dfdd-4db1-90f2-d8ba5f7af99d\",\"id\":\"8fc49615-dfdd-4db1-90f2-d8ba5f7af99d\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":3720}", 
	
*/	
	
	lr_end_transaction("UC02_TR03_create_new_test",LR_AUTO);

	lr_start_transaction("UC02_TR04_sign_out");

	lr_end_transaction("UC02_TR04_sign_out",LR_AUTO);

	return 0;
}