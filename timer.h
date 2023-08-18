//////////////////    Class definition   ////////////////////////////////


typedef void(*function_cb)();

class timer_debounce_switch
{
  public:
      void SetTimeout(uint32_t time, function_cb foo) {
      if (!m_waitExpired ) {
        m_function = foo;
        m_boolPtr = nullptr;
        m_timeout = time;
        m_waitExpired = true;
        m_startTime = millis();
      }
    }
/**************************************************************************/
/*!
     @brief  Checks to see if delay time has passed and can then run code
	 Will run function call if one was used
     
     @bool: true if time to update, false if not 
*/
/**************************************************************************/
    void run() {
      if (millis() - m_startTime > m_timeout && m_waitExpired) {
        m_startTime = millis();
        if (m_function != nullptr) {
          m_function();
        }
        if (m_boolPtr != nullptr) {
          *m_boolPtr = true;
        }
        m_waitExpired = false;
      }
    }

  private:
    function_cb m_function;
    bool*       m_boolPtr;

    uint32_t    m_timeout;
    uint32_t    m_startTime;
    bool        m_waitExpired;
};

//////////////////////////////////////////////////////////////////////////////


//////////////////    Class definition   ////////////////////////////////

class timer_igniter
{
  public:
      void SetTimeout(uint32_t time, function_cb foo) {
      if (!m_waitExpired ) {
        m_function = foo;
        m_boolPtr = nullptr;
        m_timeout = time;
        m_waitExpired = true;
        m_startTime = millis();
      }
    }
/**************************************************************************/
/*!
     @brief  Checks to see if delay time has passed and can then run code
	 Will run function call if one was used
     
     @bool: true if time to update, false if not 
*/
/**************************************************************************/
    void run() {
      if (millis() - m_startTime > m_timeout && m_waitExpired) {
        m_startTime = millis();
        if (m_function != nullptr) {
          m_function();
        }
        if (m_boolPtr != nullptr) {
          *m_boolPtr = true;
        }
        m_waitExpired = false;
      }
    }

  private:
    function_cb m_function;
    bool*       m_boolPtr;

    uint32_t    m_timeout;
    uint32_t    m_startTime;
    bool        m_waitExpired;
};

////////////////////////////////////////////////////////////////////////////////


//////////////////    Class definition   ////////////////////////////////

class timer_periodical_print
{
  public:
      void SetTimeout(uint32_t time, function_cb foo) {
      if (!m_waitExpired ) {
        m_function = foo;
        m_boolPtr = nullptr;
        m_timeout = time;
        m_waitExpired = true;
        m_startTime = millis();
      }
    }
/**************************************************************************/
/*!
     @brief  Checks to see if delay time has passed and can then run code
	 Will run function call if one was used
     
     @bool: true if time to update, false if not 
*/
/**************************************************************************/
    void run() {
      if (millis() - m_startTime > m_timeout && m_waitExpired) {
        m_startTime = millis();
        if (m_function != nullptr) {
          m_function();
        }
        if (m_boolPtr != nullptr) {
          *m_boolPtr = true;
        }
        m_waitExpired = false;
      }
    }

  private:
    function_cb m_function;
    bool*       m_boolPtr;

    uint32_t    m_timeout;
    uint32_t    m_startTime;
    bool        m_waitExpired;
};

////////////////////////////////////////////////////////////////////////////////