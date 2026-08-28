// ============================================================
// BACKWARD COMPATIBILITY
// ============================================================
//
// Backward compatibility means:
//
// When we add new features or improve existing code,
// the old code should continue to work.
//
// In other words:
//
//     New features
//          ↓
//     Old code still works
//          ↓
//     Nothing that depended on the old code is broken.
//
// ============================================================



// ============================================================
// Example - GetDifferenceInDays()
// ============================================================
//
// Originally, we had a function that calculates the
// difference between two dates.
//
// ============================================================

unsigned short GetDifferenceInDays(
    sDate Date1,
    sDate Date2,
    bool IncludeEndDay = false)
{
    unsigned short Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? ++Days : Days;
}



// ============================================================
// Existing Code
// ============================================================
//
// Other parts of the project may already use this function.
//
// For example:
//
// ============================================================

short Difference = GetDifferenceInDays(Date1, Date2);



// ============================================================
// New Requirement
// ============================================================
//
// Now we want to add a new feature:
//
// The function should also work when Date1 is after Date2.
//
// Example:
//
//     Date1 = 2025
//     Date2 = 2020
//
// The result should be negative.
//
//
//     Date1 = 2025
//     Date2 = 2020
//
//            ↓
//
//     Difference = -1827 days
//
// ============================================================


// ============================================================
// Adding The New Feature
// ============================================================
//
// We can modify the implementation of the function
// without changing the way existing code calls it.
//
// ============================================================

short GetDifferenceInDays(
    sDate Date1,
    sDate Date2,
    bool IncludeEndDay = false)
{
    short Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        // Swap the dates so that Date1 is always
        // before Date2 during the calculation.

        SwapDates(Date1, Date2);

        // Remember that the original Date1 was after Date2.
        // Therefore the final result must be negative.

        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay
        ? ++Days * SwapFlagValue
        : Days * SwapFlagValue;
}



// ============================================================
// Where Is Backward Compatibility?
// ============================================================
//
// Notice that the function can still be called exactly
// the same way as before.
//
// Old code:
//
//     GetDifferenceInDays(Date1, Date2);
//
//
//
// New implementation:
//
//     GetDifferenceInDays(Date1, Date2);
//
//
//
// The way we call the function did NOT change.
//
// ============================================================



// ============================================================
// Function Interface
// ============================================================
//
// The function still accepts:
//
//     sDate Date1
//     sDate Date2
//     bool IncludeEndDay = false
//
// Therefore existing code that calls:
//
//     GetDifferenceInDays(Date1, Date2);
//
// does not need to be changed.
//
// ============================================================



// ============================================================
// Why Is This Important?
// ============================================================
//
// Imagine a large project.
//
// There may be many places calling this function:
//
//     GetDifferenceInDays(Date1, Date2);
//
//     GetDifferenceInDays(StartDate, EndDate);
//
//     GetDifferenceInDays(BirthDate, Today);
//
//     GetDifferenceInDays(Date1, Date2, true);
//
//
//
// If we change the function interface,
// we may have to modify all of these places.
//
// If the old calls stop working,
// we have broken backward compatibility.
//
// ============================================================



// ============================================================
// Bad Example - Breaking Backward Compatibility
// ============================================================
//
// Suppose we changed the function to:
//
//     GetDifferenceInDays(
//         sDate Date1,
//         sDate Date2,
//         bool IncludeEndDay,
//         bool ReturnNegative);
//
//
//
// Now existing code:
//
//     GetDifferenceInDays(Date1, Date2);
//
// would no longer work.
//
// The old code would need to be changed.
//
//
//
// This means we have broken backward compatibility.
//
// ============================================================



// ============================================================
// Good Example - Preserving Backward Compatibility
// ============================================================
//
// Instead, we keep the existing interface:
//
//     GetDifferenceInDays(
//         sDate Date1,
//         sDate Date2,
//         bool IncludeEndDay = false);
//
//
//
// Then we add the new functionality inside the function.
//
//
//
// Old code:
//
//     GetDifferenceInDays(Date1, Date2);
//
// still works.
//
//
//
// New behavior:
//
//     Date1 = 2025
//     Date2 = 2020
//
// gives:
//
//     -1827
//
// ============================================================



// ============================================================
// Implementation vs Interface
// ============================================================
//
// We are allowed to change the implementation.
//
// For example, we added:
//
//     SwapDates(Date1, Date2);
//
// and:
//
//     SwapFlagValue = -1;
//
//
//
// These changes are inside the function.
//
// They do not require existing code to change how
// it calls the function.
//
//
//
// Therefore:
//
//     Implementation
//          ↓
//     Can change
//
//     Existing Interface
//          ↓
//     Should remain compatible
//
// ============================================================



// ============================================================
// Important Note About short
// ============================================================
//
// Originally:
//
//     unsigned short Days = 0;
//
//
//
// unsigned short can only represent positive values.
//
// But our new feature requires:
//
//     +100
//     -100
//
//
//
// Therefore we use:
//
//     short Days = 0;
//
//
//
// short can represent both positive and negative values.
//
// ============================================================



// ============================================================
// Backward Compatibility - Main Idea
// ============================================================
//
// The main idea is:
//
//     Add new functionality
//             ↓
//     Do not break existing code
//             ↓
//     Keep the old way of using the function
//
//
//
// In our example:
//
//     GetDifferenceInDays(Date1, Date2);
//
// was already being used.
//
// We added the ability to return negative differences,
// but we kept the existing function interface.
//
// ============================================================



// ============================================================
// Simple Example
// ============================================================
//
// Before:
//
//     GetDifferenceInDays(Date1, Date2);
//
//
//
// After adding the new feature:
//
//     GetDifferenceInDays(Date1, Date2);
//
//
//
// The call is exactly the same.
//
//
//
// But now the function supports:
//
//     Date1 < Date2  → positive result
//
//     Date1 > Date2  → negative result
//
//     Date1 == Date2 → 0
//
// ============================================================



// ============================================================
// Definition To Remember
// ============================================================
//
// Backward compatibility means:
//
// When we add new features or modify existing code,
// the old code and existing way of using the program
// continue to work without breaking.
//
//
//
// In our example:
//
// We added a new feature to GetDifferenceInDays()
// without changing its existing interface,
// so code that already uses GetDifferenceInDays()
// continues to work.
//
// ============================================================
